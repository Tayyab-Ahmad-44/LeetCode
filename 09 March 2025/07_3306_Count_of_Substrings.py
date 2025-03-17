def countOfSubstrings(word: str, k: int) -> int:
    output = 0

    for i in range (len(word)):
        sub_word = ""
        consonants = 0

        for j in range(i, len(word)):
            sub_word += word[j]
            if word[j] not in {"a", "e", "i", "o", "u"}:
                consonants += 1
                if consonants > k:
                    break
            if consonants == 2 and {"a", "e", "i", "o", "u"}.issubset(sub_word):
                output += 1
        
    
    return output

print(countOfSubstrings("iqeaouqi", 2))


