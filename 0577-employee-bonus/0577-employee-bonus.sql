# Write your MySQL query statement below
SELECT name, bonus
FROM Employee 
LEFT JOIN Bonus
ON Employee.empID= Bonus.empID
where Bonus.bonus<1000 OR Bonus.bonus is NULL; 