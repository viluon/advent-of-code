import java.io.File
import kotlin.math.absoluteValue

val reports = File("./02-red-nosed-reports.in")
    .readLines()
    .map { line ->
        line
            .split(" ")
            .filter { it.isNotBlank() }
            .map { it.toInt() }
    }

fun partOne() {
    val result = reports.count { report ->
        val increasing = report.zipWithNext().all { (a, b) -> a <= b }
        val decreasing = report.zipWithNext().all { (a, b) -> a >= b }
        report.zipWithNext { a, b ->
            (a - b).absoluteValue in 1..3
        }.all { it } && (increasing || decreasing)
    }

    println(result)
}

fun partTwo() {
    val result = reports.count { raw ->
        raw.indices.firstOrNull { toRemove ->
            val report = raw.toMutableList().apply { removeAt(toRemove) }

            val increasing = report.zipWithNext().all { (a, b) -> a <= b }
            val decreasing = report.zipWithNext().all { (a, b) -> a >= b }
            report.zipWithNext { a, b ->
                (a - b).absoluteValue in 1..3
            }.all { it } && (increasing || decreasing)
        } != null
    }

    println(result)
}

partTwo()
