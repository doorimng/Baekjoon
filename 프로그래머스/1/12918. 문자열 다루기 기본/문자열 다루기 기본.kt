class Solution {
    fun solution(s: String): Boolean {
        var answer = true
            
        if (!(s.length in 4..6 step 2 && s.all { it.isDigit() })) 
            answer = false
        
        return answer
    }
}