# AVLTree

AVLtree 는 Balanced Binary Search Tree 의 일종으로써, AVLTree 라는 이름은 개발자 **A**delson-**V**elskii 와 **L**andis 의 이름을 따와서 명명되었다. AVLTree 의 특징은 아래와 같다

- 삽입 시간:
- 삭제 시간:
- 탐색 시간:

그런데 AVLTree 는 Insertion 과 Deletion 과정에서 Balancing 을 수행하기 위해 Balance Factor 의 계산과 Rotation 등의 추가적인 작업이 필요하다. 따라서 Insertion 과 Deletion 이 짧은 주기로 호출되는 상황에는 오히려 높은 오버헤드를 발생시킬 수 있으므로, Insertion 과 Deletion 보다 Searching 이 자주 호출되는 경우에 적합하다.

AVL tree is efficient when your job have more searching than insertion.

AVL Tree 의 동작 과정은 아래의 사이트에서 확인 가능하다.
[AVL Tree Simulator](https://www.cs.usfca.edu/~galles/visualization/AVLtree.html)
