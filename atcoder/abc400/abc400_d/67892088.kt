// Date: Fri, 25 Jul 2025 12:11:05 +0000
// Language: Kotlin (Kotlin/JVM 1.8.20)
import java.util.*

fun main() {
    val (H, W) = readLine()!!.split(" ").map { it.toInt() }
    val grid = Array(H) { readLine()!!.toCharArray() }
    val (A, B, C, D) = readLine()!!.split(" ").map { it.toInt() }
    val start = Pair(A - 1, B - 1)
    val goal = Pair(C - 1, D - 1)

    val dist = Array(H) { IntArray(W) { Int.MAX_VALUE } }
    val deque: ArrayDeque<Pair<Int, Int>> = ArrayDeque()

    dist[start.first][start.second] = 0
    deque.addFirst(start)

    val directions = arrayOf(
        Pair(-1, 0),
        Pair(1, 0),
        Pair(0, -1),
        Pair(0, 1)
    )

    while (deque.isNotEmpty()) {
        val (x, y) = deque.removeFirst()
        val cost = dist[x][y]
        if (x == goal.first && y == goal.second) {
            println(cost)
            return
        }

        for ((dx, dy) in directions) {
            val nx = x + dx
            val ny = y + dy
            if (nx in 0 until H && ny in 0 until W && grid[nx][ny] == '.' && dist[nx][ny] > cost) {
                dist[nx][ny] = cost
                deque.addFirst(Pair(nx, ny))
            }
        }

        for ((dx, dy) in directions) {
            for (step in 1..2) {
                val nx = x + dx * step
                val ny = y + dy * step
                if (nx !in 0 until H || ny !in 0 until W) break
                if (grid[nx][ny] == '#') {
                    if (dist[nx][ny] > cost + 1) {
                        dist[nx][ny] = cost + 1
                        deque.addLast(Pair(nx, ny))
                    }
                } else {
                    break
                }
            }
        }
    }

    println(-1)
}
