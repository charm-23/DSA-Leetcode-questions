# Write your MySQL query statement below
SELECT person_name
FROM (
    select *, SUM(weight) OVER(ORDER BY turn) as total_sum
    FROM Queue
) as t
Where total_sum<=1000 
order by turn desc
limit 1;