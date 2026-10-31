# Write your MySQL query statement below
WITH new_table AS(
    SELECT num, LAG(num,1) OVER(ORDER BY id) AS prev1, LAG(num,2) OVER(ORDER BY id) AS prev2
    FROM Logs
)

SELECT distinct num as ConsecutiveNums
FROM new_table
WHERE num=prev1 AND num=prev2; 