SELECT c.customer_id, COUNT(*) AS count_no_trans
FROM Visits AS c
LEFT JOIN Transactions AS t
ON c.visit_id = t.visit_id
WHERE t.visit_id IS NULL
GROUP BY c.customer_id;
