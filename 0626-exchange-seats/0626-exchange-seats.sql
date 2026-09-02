SELECT 
    s1.id,
    CASE
        WHEN s1.id % 2 = 1 
            THEN COALESCE(s2.student, s1.student)
        ELSE s2.student
    END AS student
FROM Seat s1
LEFT JOIN Seat s2
    ON s2.id = CASE
                  WHEN s1.id % 2 = 1 THEN s1.id + 1
                  ELSE s1.id - 1
               END
ORDER BY s1.id;