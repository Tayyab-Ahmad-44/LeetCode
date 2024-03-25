from typing import List

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freq = {}
        ans = 0
        done = False
        left = 0
        
        for task in tasks:
            freq[task] = freq.get(task, 0) + 1
        
        valss = list(freq.values())
        vals = sorted(valss, reverse= True)
        
        print(vals)
        
        # for k in range(3):
        while not done:
            cnt = n+1
            m = 0
            # print("A")
            for i in range(len(vals)):
                # print(f"{vals[i]}\t{ans}")
                
                if vals[i] > 0:
                    vals[i] -= 1
                    cnt -= 1
                    ans += 1 
                    # print(f"{ans}")
                    left = cnt
                    print(vals[i])
                    if cnt == 0:
                        print(f"{cnt}\t{ans}")
                        break
                else:
                    m+=1

                if m == len(vals):
                    # print(done)
                    done = True
                    break

            # print(cnt)
            if not done:
                # print("hi")
                while cnt > 0:
                    # print(f"Ideal {ans}")
                    ans += 1
                    cnt -= 1
            # break
        
        print(ans - left)

sol = Solution()

# tasks = ["A","A","A","B","B","B"]
# n = 2

# tasks = ["A","C","A","B","D","B"]
# n = 1

# tasks = ["A","A","A", "B","B","B"]
# n = 3

# tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"]
# n = 1

# tasks = ["A","A","A","B","B","B", "C","C","C", "D", "D", "E"]
# n = 2

sol.leastInterval(tasks, n)
            
    
"""
621. Task Scheduler

You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.

​Return the minimum number of intervals required to complete all tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
After completing task A, you must wait two cycles before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th cycle, you can do A again as 2 intervals have passed.

Example 2:
Input: tasks = ["A","C","A","B","D","B"], n = 1
Output: 6
Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:
Input: tasks = ["A","A","A", "B","B","B"], n = 3
Output: 10
Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.
"""