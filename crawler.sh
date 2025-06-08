#!/usr/bin/env bash

git config user.name "ecto0310"
git config user.email "48977990+ecto0310@users.noreply.github.com"
git remote set-url origin https://ecto0310:${GITHUB_TOKEN}@github.com/${GITHUB_REPOSITORY}

atcoder_username="ecto0310"
codeforces_username="ecto0310"
aoj_username="ecto0310"
yukicoder_userid="7577"

get_extension() {
    case "$1" in
    *JavaScript*) echo "js" ;;
    *MoonScript*) echo "moon" ;;
    *TypeScript*) echo "ts" ;;
    *Brainfuck*) echo "bf" ;;
    *Objective*) echo "m" ;;
    *Unlambda*) echo "unl" ;;
    *Clojure*) echo "clj" ;;
    *Crystal*) echo "cr" ;;
    *Fortran*) echo "f" ;;
    *Haskell*) echo "hs" ;;
    *Delphi*) echo "pas" ;;
    *Kotlin*) echo "kt" ;;
    *Octave*) echo "m" ;;
    *Python*) echo "py" ;;
    *Pascal*) echo "pas" ;;
    *Scheme*) echo "ss" ;;
    *Basic*) echo "vb" ;;
    *COBOL*) echo "cobol" ;;
    *Julia*) echo "jl" ;;
    *OCaml*) echo "ml" ;;
    *Swift*) echo "swift" ;;
    *Scala*) echo "scala" ;;
    *Bash*) echo "sh" ;;
    *Java*) echo "java" ;;
    *Lisp*) echo "lisp" ;;
    *Perl*) echo "pl" ;;
    *Ruby*) echo "rb" ;;
    *Rust*) echo "rs" ;;
    *Text*) echo "txt" ;;
    *Awk*) echo "awk" ;;
    *C++*) echo "cpp" ;;
    *Nim*) echo "nim" ;;
    *PHP*) echo "php" ;;
    *Sed*) echo "sed" ;;
    *C#*) echo "cs" ;;
    *F#*) echo "fs" ;;
    *Go*) echo "go" ;;
    *ML*) echo "sml" ;;
    *C*) echo "c" ;;
    *D*) echo "d" ;;
    **) echo "unknown" ;;
    esac
}

IFS=$'\n'

new_submissions="[]"

echo "Start AtCoder submissions check"

exists=()

for exists_id in $(find "atcoder" -type f | gawk -F/ '{print $NF}' | cut -d . -f 1); do
    exists[${exists_id}]=1
done

atcoder_last_from_second=$(cat atcoder/last_from_second 2>/dev/null || echo 0)

while true; do
    atcoder_submissions=$(
        curl -so- --compressed https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user=${atcoder_username}\&from_second=${atcoder_last_from_second} |
            jq -c '.[]'
    )

    if [ "${atcoder_submissions}" = "" ]; then
        break
    fi

    for atcoder_submission in ${atcoder_submissions}; do
        for cmd in $(echo ${atcoder_submission} | jq -r 'to_entries|map("\(.key)=\"\(.value)\"")|.[]'); do
            eval ${cmd}
        done

        atcoder_last_from_second=$(expr ${epoch_second} + 1)

        if [ "${result}" != "AC" ] || [ "${exists[${id}]}" = "1" ]; then
            continue
        fi

        new_submissions=$(
            echo ${new_submissions} |
                jq '.|=.+[{"site":"atcoder","time":"'${epoch_second}'","id":"'${id}'","contest_id":"'${contest_id}'","problem_id":"'${problem_id}'","language":"'${language}'"}]'
        )
    done

    sleep 0.5
done

echo "Finish AtCoder submissions check"

echo "Start Codeforces submissions check"

exists=()

for exists_id in $(find "codeforces" -type f | gawk -F/ '{print $NF}' | cut -d . -f 1); do
    exists[${exists_id}]=1
done

codeforces_submissions=$(
    curl -so- https://codeforces.com/api/user.status?handle=${codeforces_username} |
        jq -c '.result[]'
)

for codeforces_submission in ${codeforces_submissions}; do
    codeforces_submission=$(echo ${codeforces_submission} | jq '.|=.+{"index":(.problem.index)}|del(.problem)|del(.author)')
    for cmd in $(echo ${codeforces_submission} | jq -r 'to_entries|map("\(.key)=\"\(.value)\"")|.[]'); do
        eval ${cmd}
    done

    if [ "${verdict}" != "OK" ] || [ "${exists[${id}]}" = "1" ]; then
        continue
    fi

    new_submissions=$(
        echo ${new_submissions} |
            jq '.|=.+[{"site":"codeforces","time":"'${creationTimeSeconds}'","id":"'${id}'","contest_id":"'${contestId}'","problem_id":"'${contestId}'_'${index,,}'","language":"'${programmingLanguage}'"}]'
    )
done

echo "Finish Codeforces submissions check"
echo "Start AOJ submissions check"

exists=()

for exists_id in $(find "aizu_online_judge" -type f | gawk -F/ '{print $NF}' | cut -d . -f 1); do
    exists[${exists_id}]=1
done

aoj_submissions=$(
    curl -so- --compressed https://judgeapi.u-aizu.ac.jp/solutions/users/${aoj_username} |
        jq -c '.[]'
)

for aoj_submission in ${aoj_submissions}; do
    for cmd in $(echo ${aoj_submission} | jq -r 'to_entries|map("\(.key)=\"\(.value)\"")|.[]'); do
        eval ${cmd}
    done

    if [ "${exists[${judgeId}]}" = "1" ]; then
        continue
    fi

    new_submissions=$(
        echo ${new_submissions} |
            jq '.|=.+[{"site":"AOJ","time":"'${submissionDate:0:10}'","id":"'${judgeId}'","problem_id":"'${problemId}'","language":"'${language}'"}]'
    )
done

echo "Finish AOJ submissions check"
echo "Start Yukicoder submissions check"

exists=()

for exists_id in $(find "yukicoder" -type f | gawk -F/ '{print $NF}' | cut -d . -f 1); do
    exists[${exists_id}]=1
done

page=1
while true; do
    first=$(
        curl -so- --compressed 'https://yukicoder.me/users/'${yukicoder_userid}'/submissions?status=AC&page='${page} |
            dos2unix |
            xmllint --xpath '//*[@id="content"]/div[2]/table/tbody/tr[1]' --html - 2>/dev/null
    )
    if [ "${first}" = "" ]; then
        break
    fi
    pageData=$(
        curl -so- --compressed 'https://yukicoder.me/users/'${yukicoder_userid}'/submissions?status=AC&page='${page} |
            dos2unix |
            xmllint --xpath '//*[@id="content"]/div[2]/table/tbody' --html - 2>/dev/null
    )
    for index in $(seq 1 50); do
        data=$(
            echo "${pageData}" |
                xmllint --xpath '//tr['${index}']' --html - 2>/dev/null
        )
        id=$(
            echo "${data}" |
                xmllint --xpath '//tr/td[1]/a/text()' --html - 2>/dev/null
        )
        if [ "${id}" = "" ] || [ "${exists[${id}]}" = "1" ]; then
            continue
        fi

        submissionDate=$(
            echo "${data}" |
                xmllint --xpath '//tr/td[2]/text()' --html - 2>/dev/null
        )
        submissionDate=$(date --date=${submissionDate} +%s)
        problemId=$(
            echo "${data}" |
                xmllint --xpath '//tr/td[5]/a/@href' --html - 2>/dev/null |
                sed 's/ href=\"\/problems\/no\///; s/\"//'
        )
        language=$(
            echo "${data}" |
                xmllint --xpath '//tr/td[6]/text()' --html - 2>/dev/null
        )

        new_submissions=$(
            echo ${new_submissions} |
                jq '.|=.+[{"site":"yukicoder","time":"'${submissionDate}'","id":"'${id}'","problem_id":"'${problemId}'","language":"'${language}'"}]'
        )
    done
    page=$(expr $page + 1)

    sleep 0.5
done

echo "Finish Yukicoder submissions check"
echo "Start fetching new submissions"

new_submissions=$(echo ${new_submissions} | jq -c 'sort_by(.time) | .[]')

count=0

for new_submission in ${new_submissions}; do
    for cmd in $(echo ${new_submission} | jq -r 'to_entries|map("\(.key)=\"\(.value)\"")|.[]'); do
        eval ${cmd}
    done

    echo "Fetching submission #${id}(${site})"

    if [ "${site}" = "atcoder" ]; then
        directory="atcoder/${contest_id}/${problem_id}"
        filename="${directory}/${id}.$(get_extension ${language})"
        code=$(
            curl -so- "https://atcoder.jp/contests/${contest_id}/submissions/${id}" |
                dos2unix |
                xmllint --xpath '//*[@id="submission-code"]/text()' --html - 2>/dev/null |
                sed 's/&amp;/\&/g; s/&lt;/\</g; s/&gt;/\>/g; s/&quot;/\"/g; s/#&#39;/\'"'"'/g;'
        )

    elif [ "${site}" = "codeforces" ]; then
        directory="codeforces/${contest_id}/${problem_id}"
        filename="${directory}/${id}.$(get_extension ${language})"
        code=$(
            curl -so- "https://codeforces.com/contest/${contest_id}/submission/${id}" |
                dos2unix |
                xmllint --xpath '//*[@id="program-source-text"]/text()' --html - 2>/dev/null |
                sed 's/&amp;/\&/g; s/&lt;/\</g; s/&gt;/\>/g; s/&quot;/\"/g; s/#&#39;/\'"'"'/g;'
        )

    elif [ "${site}" = "AOJ" ]; then
        directory="aizu_online_judge/${problem_id}"
        filename="${directory}/${id}.$(get_extension ${language})"
        code=$(
            curl -so- "https://judgeapi.u-aizu.ac.jp/reviews/${id}" |
                dos2unix |
                jq -r '.sourceCode'
        )

    elif [ "${site}" = "yukicoder" ]; then
        directory="yukicoder/${problem_id}"
        filename="${directory}/${id}.$(get_extension ${language})"
        code=$(
            curl -so- "https://yukicoder.me/submissions/${id}/source" |
                dos2unix
        )
    fi

    header="// Date: $(date -d @${time} -R)"$'\n'"// Language: ${language}"
    mkdir -p "${directory}"
    echo "${header}"$'\n'"${code}" >${filename}

    git add ${filename}
    git commit -a -m "[add] ${filename}" --date="$(date -d @${time} -R)"

    let count++

    sleep 0.5
done

git rebase --committer-date-is-author-date HEAD~${count}

echo "Finish fetching new submissions"

echo "Update AtCoder last submission time"

echo ${atcoder_last_from_second} >atcoder/last_from_second
git add atcoder/last_from_second
git commit -m "[update] atcoder/last_from_second"

git push origin main

echo "Successfully all process"
