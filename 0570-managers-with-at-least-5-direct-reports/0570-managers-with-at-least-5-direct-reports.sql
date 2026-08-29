# Write your MySQL query statement below
SELECT B.name
FROM Employee as A
JOIN Employee as B
On A.managerId=B.id
GROUP BY A.managerID
Having count(A.id)>=5; 
