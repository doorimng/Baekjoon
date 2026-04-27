fun main(args: Array<String>) {
    val a = readLine()!!.toInt()
    
    if (a % 2 == 1) println("%d is odd".format(a))
    else println("%d is even".format(a))
}