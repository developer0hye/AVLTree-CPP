# AVLTree

AVLTree 는 논문(G. M. Adel'son-Vel'skii, E. M. Landis, "An algorithm for the organization of information", 1962)을 통해 제안된 **Balanced Binary Serarch Tree** 로 Tree 앞에 붙은 **AVL**은 논문의 저자인 **A**delson-**V**elskii 와 **L**andis 의 이름을 따서 지어졌다.


## Why AVLTree?

AVLTree 가 나오게 된 배경과 필요성을 피부로 느끼기 위해서는 Binary Search Tree 에 대한 이해가 필요하다.

### Binary Search Tree




## Big-O Analysis of AVLTree

- 삽입 시간: O(logN)
- 삭제 시간: O(logN)
- 탐색 시간: O(logN)

### When should we use AVL trees?

그렇다면 AVLTree 는 어떠한 경우에 사용하면 좋을까?


AVLTree 는 Insertion 과 Deletion 과정에서 Balancing 을 수행하기 위해 Balance Factor 의 계산과 Rotation 등의 추가적인 작업이 필요하다. 따라서 Insertion 과 Deletion 이 짧은 주기로 호출되는 상황에는 높은 오버헤드를 발생시킬 수 있으므로, Insertion 과 Deletion 이 자주 호출되지 않는 선에서 Searching 이 자주 호출되는 경우에 적합하다.

AVL tree is efficient when your job have more searching than insertion.

AVL Tree 의 동작 과정은 아래의 사이트에서 확인 가능하다.
[AVL Tree Simulator](https://www.cs.usfca.edu/~galles/visualization/AVLtree.html)
