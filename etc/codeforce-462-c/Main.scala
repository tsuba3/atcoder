import scala.io.StdIn.readLine

object Main {
  def main(args: Array[String]): Unit = {
    readLine()
    val a = readLine().split(" ").map(_.toLong)
    val ans = if (a.length == 1) {
      a.head.toLong
    } else {
      a.sorted.zipWithIndex.map { case
        (x, i) => x * (i + 2)
      }.sum - a.max
    }
    println(ans)
  }
}
