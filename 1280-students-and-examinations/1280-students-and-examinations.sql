SELECT 
    s.student_id,
    s.student_name,
    sub.subject_name,
    COUNT(ex.subject_name) AS attended_exams
FROM Students AS s
CROSS JOIN Subjects AS sub
LEFT JOIN Examinations AS ex
ON sub.subject_name = ex.subject_name
AND s.student_id = ex.student_id
GROUP BY 
    s.student_id,
    s.student_name,
    sub.subject_name
ORDER BY 
    s.student_id,
    sub.subject_name;