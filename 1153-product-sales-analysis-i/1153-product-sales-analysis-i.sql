# Write your MySQL query statement below
select p.product_name,s.year,s.price from Sales AS s INNER JOIN Product AS p ON p.product_id = s.product_id;