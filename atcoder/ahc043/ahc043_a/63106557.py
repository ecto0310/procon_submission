// Date: Sun, 23 Feb 2025 17:52:15 +0000
// Language: Python (PyPy 3.10-v7.3.12)
import sys

Pos = tuple[int, int]
EMPTY = -1
DO_NOTHING = -1
STATION = 0
RAIL_HORIZONTAL = 1
RAIL_VERTICAL = 2
RAIL_LEFT_DOWN = 3
RAIL_LEFT_UP = 4
RAIL_RIGHT_UP = 5
RAIL_RIGHT_DOWN = 6
COST_STATION = 5000
COST_RAIL = 100


class UnionFind:
    def __init__(self, n: int):
        self.n = n
        self.parents = [-1 for _ in range(n * n)]

    def _find_root(self, idx: int) -> int:
        if self.parents[idx] < 0:
            return idx
        self.parents[idx] = self._find_root(self.parents[idx])
        return self.parents[idx]

    def is_same(self, p: Pos, q: Pos) -> bool:
        p_idx = p[0] * self.n + p[1]
        q_idx = q[0] * self.n + q[1]
        return self._find_root(p_idx) == self._find_root(q_idx)

    def unite(self, p: Pos, q: Pos) -> None:
        p_idx = p[0] * self.n + p[1]
        q_idx = q[0] * self.n + q[1]
        p_root = self._find_root(p_idx)
        q_root = self._find_root(q_idx)
        if p_root != q_root:
            p_size = -self.parents[p_root]
            q_size = -self.parents[q_root]
            if p_size > q_size:
                p_root, q_root = q_root, p_root
            self.parents[q_root] += self.parents[p_root]
            self.parents[p_root] = q_root


def distance(a: Pos, b: Pos) -> int:
    return abs(a[0] - b[0]) + abs(a[1] - b[1])


class Action:
    def __init__(self, type: int, pos: Pos):
        self.type = type
        self.pos = pos

    def __str__(self):
        if self.type == DO_NOTHING:
            return "-1"
        else:
            return f"{self.type} {self.pos[0]} {self.pos[1]}"


class Result:
    def __init__(self, actions: list[Action], score: int):
        self.actions = actions
        self.score = score

    def __str__(self):
        return "\n".join(map(str, self.actions))


class Field:
    def __init__(self, N: int):
        self.N = N
        self.rail = [[EMPTY] * N for _ in range(N)]
        self.uf = UnionFind(N)

    def is_empty(self, r: int, c: int) -> bool:
        return self.rail[r][c] == EMPTY

    def is_station(self, r: int, c: int) -> bool:
        return self.rail[r][c] == STATION

    def build(self, type: int, r: int, c: int) -> None:
        assert self.rail[r][c] != STATION
        if 1 <= type <= 6:
            assert self.rail[r][c] == EMPTY
        self.rail[r][c] = type

        # 隣接する区画と接続
        # 上
        if type in (STATION, RAIL_VERTICAL, RAIL_LEFT_UP, RAIL_RIGHT_UP):
            if r > 0 and self.rail[r - 1][c] in (STATION, RAIL_VERTICAL, RAIL_LEFT_DOWN, RAIL_RIGHT_DOWN):
                self.uf.unite((r, c), (r - 1, c))
        # 下
        if type in (STATION, RAIL_VERTICAL, RAIL_LEFT_DOWN, RAIL_RIGHT_DOWN):
            if r < self.N - 1 and self.rail[r + 1][c] in (STATION, RAIL_VERTICAL, RAIL_LEFT_UP, RAIL_RIGHT_UP):
                self.uf.unite((r, c), (r + 1, c))
        # 左
        if type in (STATION, RAIL_HORIZONTAL, RAIL_LEFT_DOWN, RAIL_LEFT_UP):
            if c > 0 and self.rail[r][c - 1] in (STATION, RAIL_HORIZONTAL, RAIL_RIGHT_DOWN, RAIL_RIGHT_UP):
                self.uf.unite((r, c), (r, c - 1))
        # 右
        if type in (STATION, RAIL_HORIZONTAL, RAIL_RIGHT_DOWN, RAIL_RIGHT_UP):
            if c < self.N - 1 and self.rail[r][c + 1] in (STATION, RAIL_HORIZONTAL, RAIL_LEFT_DOWN, RAIL_LEFT_UP):
                self.uf.unite((r, c), (r, c + 1))

    def is_connected(self, s: Pos, t: Pos) -> bool:
        assert distance(s, t) > 4  # 前提条件
        stations0 = self.collect_stations(s)
        stations1 = self.collect_stations(t)
        for station0 in stations0:
            for station1 in stations1:
                if self.uf.is_same(station0, station1):
                    return True
        return False

    def collect_stations(self, pos: Pos) -> list[Pos]:
        stations = []
        for dr in range(-2, 3):
            for dc in range(-2, 3):
                if abs(dr) + abs(dc) > 2:
                    continue
                r = pos[0] + dr
                c = pos[1] + dc
                if 0 <= r < self.N and 0 <= c < self.N and self.rail[r][c] == STATION:
                    stations.append((r, c))
        return stations


class Solver:
    def __init__(self, N: int, M: int, K: int, T: int, home: list[Pos], workplace: list[Pos]):
        self.N = N
        self.M = M
        self.K = K
        self.T = T
        self.home = home.copy()
        self.workplace = workplace.copy()
        self.calc_home = home
        self.calc_workplace = workplace
        self.stations = []
        self.field = Field(N)
        self.money = K
        self.actions = []
        self.near_user = set()
        self.ok_user = set()

    def calc_income(self) -> int:
        income = 0
        for i in range(self.M):
            if self.field.is_connected(self.calc_home[i], self.calc_workplace[i]):
                income += distance(self.calc_home[i], self.calc_workplace[i])
        return income

    def build_rail(self, type: int, r: int, c: int) -> None:
        self.field.build(type, r, c)
        self.money -= COST_RAIL
        self.actions.append(Action(type, (r, c)))
        income = self.calc_income()
        self.money += income

    def build_station(self, r: int, c: int) -> None:
        for person_idx in range(self.M):
            if distance(self.calc_home[person_idx], (r, c)) <= 2 or distance(self.calc_workplace[person_idx], (r, c)) <= 2:
                self.near_user.add(person_idx)
            if distance(self.home[person_idx], (r, c)) <= 2:
                self.home[person_idx] = (r, c)
            if distance(self.home[person_idx], (r, c)) <= 2:
                self.home[person_idx] = (r, c)
            if distance(self.workplace[person_idx], (r, c)) <= 2:
                self.workplace[person_idx] = (r, c)
            if distance(self.workplace[person_idx], (r, c)) <= 2:
                self.workplace[person_idx] = (r, c)
        self.field.build(STATION, r, c)
        self.stations.append((r, c))
        self.money -= COST_STATION
        self.actions.append(Action(STATION, (r, c)))
        income = self.calc_income()
        self.money += income

    def build_nothing(self) -> None:
        self.actions.append(Action(DO_NOTHING, (0, 0)))
        income = self.calc_income()
        self.money += income

    def solve(self) -> Result:

        rail_count = (self.money - COST_STATION * 2) // COST_RAIL
        select_person_idx = -1
        select_benefit = 0
        select_in_count = []
        for person_idx in range(0, self.M):
            dist = distance(self.home[person_idx],
                            self.workplace[person_idx])
            if rail_count < dist - 1:
                continue
            benefit = (self.T - len(self.actions) - dist - 1) * \
                dist - COST_STATION * 2 - COST_RAIL * (dist - 1)
            if len(self.actions) + dist + 1 <= self.T and \
                    self.check_build(person_idx):
                in_count = []
                for near_person_idx in range(0, self.M):
                    if distance(self.home[person_idx], self.home[near_person_idx]) <= 2 or \
                        distance(self.home[person_idx], self.workplace[near_person_idx]) <= 2 or \
                        distance(self.workplace[person_idx], self.home[near_person_idx]) <= 2 or  \
                        distance(
                            self.workplace[person_idx], self.workplace[near_person_idx]) <= 2:
                        in_count.append(near_person_idx)
                if (4 <= len(select_in_count) or len(select_in_count) <= len(in_count)) and select_benefit < benefit:
                    select_benefit = benefit
                    select_person_idx = person_idx
                    select_in_count = in_count
        print(f'# {select_person_idx} {select_benefit}')
        if select_person_idx == -1:
            while len(self.actions) < self.T:
                self.build_nothing()
            return Result(self.actions, self.money)

        # 駅の配置
        self.build_station(*self.home[select_person_idx])
        self.build_station(*self.workplace[select_person_idx])

        # 線路を配置して駅を接続する
        r0, c0 = self.home[select_person_idx]
        r1, c1 = self.workplace[select_person_idx]
        print(f'# {r0} {c0} -> {r1} {c1}')
        # r0 -> r1
        if r0 < r1:
            for r in range(r0 + 1, r1):
                self.build_rail(RAIL_VERTICAL, r, c0)
            if c0 < c1:
                self.build_rail(RAIL_RIGHT_UP, r1, c0)
            elif c0 > c1:
                self.build_rail(RAIL_LEFT_UP, r1, c0)
        elif r0 > r1:
            for r in range(r0 - 1, r1, -1):
                self.build_rail(RAIL_VERTICAL, r, c0)
            if c0 < c1:
                self.build_rail(RAIL_RIGHT_DOWN, r1, c0)
            elif c0 > c1:
                self.build_rail(RAIL_LEFT_DOWN, r1, c0)
        # c0 -> c1
        if c0 < c1:
            for c in range(c0 + 1, c1):
                self.build_rail(RAIL_HORIZONTAL, r1, c)
        elif c0 > c1:
            for c in range(c0 - 1, c1, -1):
                self.build_rail(RAIL_HORIZONTAL, r1, c)

        for person_idx in self.near_user - self.ok_user:
            for station in self.stations:
                if distance(self.home[person_idx], station) <= 2:
                    self.home[person_idx] = station
                if distance(self.home[person_idx], station) <= 2:
                    self.home[person_idx] = station
                if distance(self.workplace[person_idx], station) <= 2:
                    self.workplace[person_idx] = station
                if distance(self.workplace[person_idx], station) <= 2:
                    self.workplace[person_idx] = station

        self.ok_user = self.ok_user | set(filter(
            lambda x:  self.home[x] in self.stations and self.workplace[x] in self.stations, self.near_user))

        while len(self.actions) < self.T:
            if self.money - COST_STATION < 0:
                self.build_nothing()
                continue
            rail_count = (self.money - COST_STATION) // COST_RAIL
            select_person_idx = -1
            select_benefit = 0
            for person_idx in self.near_user:
                dist = distance(self.home[person_idx],
                                self.workplace[person_idx])
                if rail_count < dist - 1:
                    continue
                benefit = (self.T - len(self.actions) - dist - 2) * \
                    dist - COST_STATION - COST_RAIL * (dist - 1)
                if len(self.actions) + dist + 1 <= self.T and \
                        select_benefit < benefit and \
                        self.check_build(person_idx):
                    select_benefit = benefit
                    select_person_idx = person_idx
            if select_person_idx == -1:
                self.build_nothing()
                continue

            # 駅の配置
            print(
                f'# {select_person_idx} {self.home[select_person_idx]} {self.workplace[select_person_idx]}')
            r0, c0 = self.home[select_person_idx]
            if not self.field.is_station(r0, c0):
                self.build_station(*self.home[select_person_idx])
            r1, c1 = self.workplace[select_person_idx]
            if not self.field.is_station(r1, c1):
                self.build_station(*self.workplace[select_person_idx])

            # 線路を配置して駅を接続する
            # r0 -> r1
            if r0 < r1:
                for r in range(r0 + 1, r1):
                    self.build_rail(RAIL_VERTICAL, r, c0)
                if c0 < c1:
                    self.build_rail(RAIL_RIGHT_UP, r1, c0)
                elif c0 > c1:
                    self.build_rail(RAIL_LEFT_UP, r1, c0)
            elif r0 > r1:
                for r in range(r0 - 1, r1, -1):
                    self.build_rail(RAIL_VERTICAL, r, c0)
                if c0 < c1:
                    self.build_rail(RAIL_RIGHT_DOWN, r1, c0)
                elif c0 > c1:
                    self.build_rail(RAIL_LEFT_DOWN, r1, c0)
            # c0 -> c1
            if c0 < c1:
                for c in range(c0 + 1, c1):
                    self.build_rail(RAIL_HORIZONTAL, r1, c)
            elif c0 > c1:
                for c in range(c0 - 1, c1, -1):
                    self.build_rail(RAIL_HORIZONTAL, r1, c)

            self.ok_user = self.ok_user | set(filter(
                lambda x:  self.home[x] in self.stations and self.workplace[x] in self.stations, self.near_user))

        while len(self.actions) < self.T:
            self.build_nothing()

        return Result(self.actions, self.money)

    def check_build(self, select_person_idx: int) -> bool:
        # 線路を配置して駅を接続する
        r0, c0 = self.home[select_person_idx]
        r1, c1 = self.workplace[select_person_idx]

        if not self.field.is_empty(r0, c0) and not self.field.is_station(r0, c0):
            return False
        if not self.field.is_empty(r1, c1) and not self.field.is_station(r1, c1):
            return False

        # r0 -> r1
        if r0 < r1:
            for r in range(r0 + 1, r1):
                if not self.field.is_empty(r, c0):
                    return False
            if c0 < c1:
                if not self.field.is_empty(r1, c0):
                    return False
            elif c0 > c1:
                if not self.field.is_empty(r1, c0):
                    return False
        elif r0 > r1:
            for r in range(r0 - 1, r1, -1):
                if not self.field.is_empty(r, c0):
                    return False
            if c0 < c1:
                if not self.field.is_empty(r1, c0):
                    return False
            elif c0 > c1:
                if not self.field.is_empty(r1, c0):
                    return False
        # c0 -> c1
        if c0 < c1:
            for c in range(c0 + 1, c1):
                if not self.field.is_empty(r1, c):
                    return False
        elif c0 > c1:
            for c in range(c0 - 1, c1, -1):
                if not self.field.is_empty(r1, c):
                    return False
        return True


def main():
    N, M, K, T = map(int, input().split())
    home = []
    workplace = []
    for _ in range(M):
        r0, c0, r1, c1 = map(int, input().split())
        home.append((r0, c0))
        workplace.append((r1, c1))

    solver = Solver(N, M, K, T, home, workplace)
    result = solver.solve()
    print(result)
    print(f"score={result.score}", file=sys.stderr)


if __name__ == "__main__":
    main()
