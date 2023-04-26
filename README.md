# DeliveryRouteFinder

* INTRODUCTION

In our project, we focus on minimizing distribution centers(Warehouses) and reducing paths for each demand point(Houses) such that the overall path covered by the delivery vans is minimum and optimized in terms of cost and profit.



* ABOUT THE PROJECT

1. This project is based on finding a minimum path for delivery vans to deliver the packages from distribution centers to different destination points. 
2. In this project we will use Weighted Graph data structures to connect all the Nodes representing warehouses, houses and Gas stations in the graph with the Edges which will represent the path between them (in terms of distance and time taken to travel).
3. Each Node in the graph will contain an integer value which will represent the addresses of that particular node in the    graph.
4. Also, it will contain a variable of Character data type which represents the type of node. Where, G represents Gas Stations, W represents warehouses and H represents Houses.



* OBJECTIVES

1. Distance: The distance between the origin and destination points is a critical factor in determining the delivery route. The shorter the distance, the more efficient and cost-effective the delivery route.
2. Delivery schedule: The delivery schedule and delivery windows determine the time and frequency of deliveries. The delivery route must be optimized to ensure timely delivery within the designated time window.
3. Route optimization is about finding the most efficient, cost-effective sequence of stops for completing the plan. 
4. Route optimization algorithms can compare billions of possibilities to come up with the most efficient routes. 
5. Shorter routes means less distance driven, which means lower operating costs because you’re using less fuel and fewer driver hours.



* Features

1. Gives the starting point as any warehouse present  in the graph to the vans according to the maximum number of houses present near that warehouse so that it will deliver all the packages in minimum cost and time. For this we will use Floyd Warshal’s Algorithm which gives us the shortest distances for every pair of houses and warehouses.
2. Van Driver will get a list which provides the details about the packages and their delivery address so that we should include those locations in the path of the van.
3. Shows the shortest time/distance path to the van owner as required from each warehouse to deliver the packages to each and every house present in the list. For this we will use the Dijkstra Algorithm or Bellman Ford Algorithm which gives us the shortest distances from warehouses to different houses.
4. There is a fixed tank Capacity for each van to travel a particular distance, So each van has to visit the gas station present in the graph to refill the tank.We will use Dijkstra’s Algorithm to get the path of nearest gas station.
5. We will also get the values of Distance traveled by the truck to cover the path and time taken for the same(in hours).
6. There can be a Paid feature of time constraint for any particular house to deliver the package before a given time limit (In case of Emergency).



* DATA STRUCTURE AND ALGORITHMS USED

1. Data structure
        Graph
2. Algorithms
        A* Search Algorithm
        Dijkstra Algorithm : Time Complexity: O(E* logV), Auxiliary Space: O(V)
        Bellman Ford Algorithm : Time Complexity:  O(V*E), Auxiliary Space: O(E)
        Floyd Warshall Algorithm : Time Complexity: O(V3), Auxiliary Space: O(V2)