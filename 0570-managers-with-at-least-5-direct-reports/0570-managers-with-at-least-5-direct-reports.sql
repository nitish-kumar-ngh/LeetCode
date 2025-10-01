# Write your MySQL query statement below
select a.name
from Employee AS a
inner join Employee AS b
ON a.id=b.managerId
GROUP BY b.managerId
HAVING COUNT(*)>=5