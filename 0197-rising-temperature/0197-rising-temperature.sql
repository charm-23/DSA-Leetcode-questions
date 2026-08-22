# Write your MySQL query statement below
SELECT A.id
FROM Weather as A
JOIN Weather as B
ON DATE_SUB(A.recordDate, INTERVAL 1 DAY) = B.recordDate
where A.temperature>B.temperature; 