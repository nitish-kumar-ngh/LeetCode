# Write your MySQL query statement below
select eu.unique_id ,e.name from Employees AS e LEFT JOIN EmployeeUNI AS eu ON e.id=eu.id;