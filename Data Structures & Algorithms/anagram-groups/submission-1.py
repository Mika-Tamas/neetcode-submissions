class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        map_list = []
        word_list = []
        found = False
        for word_ind in range(len(strs)):
            found = False
            map_list.append({})
            for letter in strs[word_ind]:
                try:
                    map_list[len(map_list)-1].update({letter : map_list[len(map_list)-1][letter]+1})
                    print("try",word_list, map_list)
                except:
                    map_list[len(map_list)-1].update({letter : 1})
                    print("except",word_list, map_list)
            print("\033[96mbefore_check",word_list, map_list,'\033[0m')
            if word_list != []:
                for check_ind in range(len(word_list)):
                    if map_list[check_ind] == map_list[len(map_list)-1]:
                        found = True
                        map_list.pop(len(map_list)-1)
                        word_list[check_ind].append(strs[word_ind])
                        break
                if not(found):
                    word_list.append([])
                    word_list[len(word_list)-1].append(strs[word_ind])
            else:
                word_list.append([strs[word_ind]])
                print("else",word_list, map_list)
        return word_list
                
