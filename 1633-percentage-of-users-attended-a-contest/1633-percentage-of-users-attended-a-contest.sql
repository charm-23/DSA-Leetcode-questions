# Write your MySQL query statement below
SELECT contest_id, ROUND((COUNT(contest_id)/ 
                       (SELECT COUNT(*) FROM USERS))*100, 2) as percentage
FROM Register 
GROUP BY contest_id
order by percentage DESC, contest_id; 