# Write your MySQL query statement below
select e.name,b.bonus 
from Employee AS e 
LEFT JOIN Bonus AS b
ON e.empId = b.empId 
where b.bonus IS NULL or b.bonus<1000
