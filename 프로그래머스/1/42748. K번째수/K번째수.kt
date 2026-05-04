class Solution {
    fun solution(array: IntArray, commands: Array<IntArray>): IntArray {
        var answer = mutableListOf<Int>()
        
        for (command in commands) {
            val tempArray = mutableListOf<Int>()
            
            val start = command[0]
            val end = command[1] 
            val k = command[2]
            
            for (i in start-1 until end) {
                tempArray.add(array[i])
            }
            
            tempArray.sort()
            answer.add(tempArray[k-1])
        }
        
        return answer.toIntArray()
    }
}