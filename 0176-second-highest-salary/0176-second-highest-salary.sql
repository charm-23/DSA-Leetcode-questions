# Write your MySQL query statement below
WITH new_table as(
    SELECT id, salary, DENSE_RANK() OVER(ORDER BY salary DESC) as rnk
    FROM Employee
)

SELECT MAX(salary) as SecondHighestSalary 
FROM new_table
where rnk=2; 