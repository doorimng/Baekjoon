fun main(args: Array<String>) {
    val (a, b) = readLine()!!.split(' ').map(String::toInt)
    println("%d + %d = %d".format(a, b, a+b))
}