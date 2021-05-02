# assignment1

#Graphic rapresentation of the components:

![rosgraph](https://user-images.githubusercontent.com/78663960/116828578-dcf31500-ab9f-11eb-9b53-52fdecb4a2f6.png)

#How to launch:

1. start the master node with: ```roscore```
2. launch the simulator: ```rosrun stage_ros stageros $(rospack find assignment1)/world/exercise.world ```
3. launch the first: ```rosrun assignment1 num_rando```
4. launch the second node: ```rosrun assignment1 bot```

#Nodes 
There are 2 nodes, written in c++: 
1. num_rando
2. bot
The first one implements the service generates a random position for the goal.
The second one is the main node, it receives

#Custom services
Rando.srv is used for the request/reply of the custom service


