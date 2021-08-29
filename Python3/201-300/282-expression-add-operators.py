#282. Expression Add Operators (Python3) - 1212ms/23.92% 15.7MB/6.07%
class Solution:
    
    # Assume left to right precedence with +/-
    def tryAddSubtract(self, num, target):
        # Base case
        if (len(num) == 1):
            return [num] if num[0] == target else []
        
        first = num.pop(0)
        second = num.pop(0)
        sols = []
        
        addNum = [first + second]
        addNum.extend(num)
        addSols = self.tryAddSubtract(addNum, target)
        
        # Replace number with operators
        head = [str(first), "+", str(second)]
        if (len(addSols) > 0):
            sols.extend(list(map(lambda s: head + s[1:], addSols)))
        
        subNum = [first - second]
        subNum.extend(num)
        subSols = self.tryAddSubtract(subNum, target)
        
        if (len(subSols) > 0):
            head[1] = "-"
            sols.extend(list(map(lambda s: head + s[1:], subSols)))
        
        return sols
    
    
    def tryMultiply(self, num, target, start):
        # If there are no more choices to make
        if (len(num) - start == 1):
            return self.tryAddSubtract(num, target)
        
        # Solutions choosing no multiplication
        sols = self.tryMultiply(num.copy(), target, start+1)
        
        # Solutions choosing to multiply
        first = num.pop(start)
        second = num.pop(start)
        num.insert(start, first*second)
        mSols = self.tryMultiply(num, target, start)
        
        if (len(mSols) > 0):
            # Replace number with operators
            repl = [str(first), "*", str(second)]
            sols.extend(list(map(lambda s: s[0:start*2] + repl + s[start*2+1:], mSols)))
        
        return sols
    
    
    def tryCombine(self, num, target, start):
        # If there are no more choices to make
        if (len(num) - start == 1):
            return self.tryMultiply(num, target, 0)
        
        # Solutions choosing no combination
        sols = self.tryCombine(num.copy(), target, start+1)
        
        # Solutions choosing to combine
        if (num[start] != 0):
            tens = num.pop(start)
            ones = num.pop(start)
            num.insert(start, (tens * 10 + ones))
            cSols = self.tryCombine(num, target, start)
            
            for cs in cSols:
                cs[start*2] = str(cs[start*2])

                sols.append(cs)
        
        return sols
    
    
    def addOperators(self, num: str, target: int) -> List[str]:
        intlist = [int(i) for i in num]
        sols = self.tryCombine(intlist, target, 0)
        
        stringSols = list(map(lambda s: "".join(s), sols))
        
        return stringSols
