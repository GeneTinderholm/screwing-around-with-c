function comp-c {
    gcc "$1" -o "$(echo "$1" | cut -d'.' -f 1)"
}
