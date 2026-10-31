# Write your MySQL query statement below
WITH new_table as(
    select *, SUM(weight) OVER(ORDER BY turn) as total_sum
    FROM Queue
)

SELECT person_name
FROM new_table 
Where total_sum<=1000 
order by turn desc
limit 1;