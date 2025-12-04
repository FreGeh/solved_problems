# Competitive Programming Problem Log

| ID | Platform | Title | Difficulty | Status | Tags | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| 1996A | Codeforces | [Legs](./codeforces/1996A.cpp) | 800 | Solved | Binary_Search | very simple, you don't really need binary search tbh |
| 1915C | Codeforces | [Can I Square?](./codeforces/1915C.cpp) | 800 | Solved | Binary_Search | keep values you compare as small as possible |
| 1352C | Codeforces | [K-th Not Divisible by n](./codeforces/1352C.cpp) | 1200 | Solved | Binary_Search | keep it simple and choose a proper search space |
| 1666 | CSES | [Building Roads](./CSES/4.%20graph/1666_Building_Roads.cpp) | - | Solved | DFS, Graph | when discovering new component, run DFS on it to mark those now connected and then keep checking if there's any unconnected ones | 
| 1193 | CSES | [Labyrinth](./CSES/4.%20graph/1193_Labyrinth.cpp) | - | Solved | BFS, Graph | never store path history as something that adds up over time but just calculate after you found the end and then use reverse() for string |
| 847E | Codeforces | [Packmen](./codeforces/847E.cpp) | 1800 | Solved | Binary_Search | always think of a binary search problem for range stuff and then really define mathematically concise definitions for check |
| 279B | Codeforces | [Books](./codeforces/279B.cpp) | 1400 | Solved | Two_Pointers | always do a while loop to increase position of right and check if conditions has been met otherwise continue moving it |
| 76 | Leetcode | [Minimum Window Substring](./leetcode/76_minimum-window-substring.cpp) | Hard | Solved | Two_Pointers | formulate condition as simple as possible and make its checks as easy as possible |
| 2.06 | KIT | [inspection](./University/ICPC_advanced/02_treaps/06_inspection.cpp) | Hard | Solved | Treap | really think about what information you need in each node and how you accumulate when combining nodes, also don't forget overflows and use '1LL *' when multiplying other ints which could become a ll |

