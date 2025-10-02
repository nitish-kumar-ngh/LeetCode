select a.name 
FROM Employee AS a
INNER JOIN Employee AS b
ON a.id=b.managerId 
GROUP BY a.id
HAVING count(*)>=5