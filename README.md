# AVLTree

AVLTree 는 가장 초기에 개발된 Balanced Binary Search Tree 이다. Tree 앞에 붙은 **AVL** 은 해당 자료구조를 제안한 **A**delson-**V**elskii 와 **L**andis 의 이름을 따서 지어진 것이며, 1962 년에 논문("An algorithm for the organization of information")을 통해 제안되었다.


## Why AVLTree?

AVLTree 가 나오게 된 배경과 필요성을 피부로 느끼기 위해서는 Binary Search Tree 에 대한 이해가 필요하다.


AVLTree 의 특징은 아래와 같다

- 삽입 시간: O(logN)
- 삭제 시간: O(logN)
- 탐색 시간: O(logN)

그런데 AVLTree 는 Insertion 과 Deletion 과정에서 Balancing 을 수행하기 위해 Balance Factor 의 계산과 Rotation 등의 추가적인 작업이 필요하다. 따라서 Insertion 과 Deletion 이 짧은 주기로 호출되는 상황에는 높은 오버헤드를 발생시킬 수 있으므로, Insertion 과 Deletion 이 자주 호출되지 않는 선에서 Searching 이 자주 호출되는 경우에 적합하다.

AVL tree is efficient when your job have more searching than insertion.

AVL Tree 의 동작 과정은 아래의 사이트에서 확인 가능하다.
[AVL Tree Simulator](https://www.cs.usfca.edu/~galles/visualization/AVLtree.html)
