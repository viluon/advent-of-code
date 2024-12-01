import java.io.File
import kotlin.math.absoluteValue

val (left, right) = run {
    val (left, right) = File("./01-historian-hysteria.in")
        .readLines()
        .asSequence()
        .flatMap { line -> line.split(" ") }
        .filter { it.isNotBlank() }
        .map { it.toInt() }
        .withIndex()
        .partition { it.index % 2 == 0 }

    left.map { it.value }.sorted() to right.map { it.value }.sorted()
}

fun partOne() {
    val result = (left zip right).sumOf { (a, b) -> (a - b).absoluteValue }
    println(result)
}

fun partTwo() {
    val count = right.fold(mapOf<Int, Int>()) { acc, i ->
        acc + (i to (acc[i] ?: 0) + 1)
    }

    val result = left.sumOf { it * (count[it] ?: 0) }
    println(result)
}

partTwo()
