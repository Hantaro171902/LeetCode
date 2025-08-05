-- Last updated: 8/5/2025, 11:17:32 PM
SELECT c.name AS Customers
FROM Customers c
LEFT JOIN Orders o
ON c.id = o.customerId
WHERE o.customerId is NULL;