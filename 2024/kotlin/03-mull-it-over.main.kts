import java.io.File

val input = File("./03-mull-it-over.in")
    .readText()

fun partOne() {
    var i = 0
    var total = 0
    while (i < input.length) {
        if (input.substring(i).startsWith("mul(")) {
            i += 4
            val first = input.substring(i).takeWhile { it.isDigit() }
            i += first.length.coerceAtLeast(1)
            val a = first.toIntOrNull()
            if (a != null && input.substring(i).startsWith(",")) {
                i++
                val second = input.substring(i).takeWhile { it.isDigit() }
                i += second.length.coerceAtLeast(1)
                val b = second.toIntOrNull()
                if (b != null && input.substring(i).startsWith(")")) {
                    i++
                    total += a * b
                }
            }
        } else {
            i++
        }
    }

    println(total)
}

fun partTwo() {
    var i = 0
    var total = 0
    var enabled = true

    while (i < input.length) {
        if (input.substring(i).startsWith("do()")) {
            i += 4
            enabled = true
        } else if (input.substring(i).startsWith("don't()")) {
            i += 6
            enabled = false
        } else if (input.substring(i).startsWith("mul(")) {
            i += 4
            val first = input.substring(i).takeWhile { it.isDigit() }
            i += first.length.coerceAtLeast(1)
            val a = first.toIntOrNull()
            if (a != null && input.substring(i).startsWith(",")) {
                i++
                val second = input.substring(i).takeWhile { it.isDigit() }
                i += second.length.coerceAtLeast(1)
                val b = second.toIntOrNull()
                if (b != null && input.substring(i).startsWith(")")) {
                    i++
                    if (enabled) {
                        total += a * b
                    }
                }
            }
        } else {
            i++
        }
    }

    println(total)
}

partTwo()
