#12. Integer to Roman (Python3) - 61ms/20.72% 14.1MB/95.26%
class Solution:
    def intToRoman(self, num: int) -> str:
        out = ""
        while num >= 1000:
            out += "M"
            num -= 1000
        while num >= 100:
            if num >= 900:
                out += "CM"
                num -= 900
                break
            elif num >= 500:
                out += "D"
                num -= 500
            elif num >= 400:
                out += "CD"
                num -= 400
                break
            else:
                out += "C"
                num -= 100
        while num >= 10:
            if num >= 90:
                out += "XC"
                num -= 90
                break
            elif num >= 50:
                out += "L"
                num -= 50
            elif num >= 40:
                out += "XL"
                num -= 40
                break
            else:
                out += "X"
                num -= 10
        while num > 0:
            if num == 9:
                out += "IX"
                break
            elif num >= 5:
                out += "V"
                num -= 5
            elif num == 4:
                out += "IV"
                break
            else:
                out += "I"
                num -= 1
        return out
