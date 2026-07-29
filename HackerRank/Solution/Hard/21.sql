/*
Enter your query here.
*/
WITH day_hackers AS(
    SELECT DISTINCT submission_date, hacker_id
                                         FROM Submissions),
    streak AS(
        SELECT submission_date, hacker_id,
        DATEDIFF(submission_date, (SELECT MIN(submission_date) FROM Submissions)) + 1 AS day_num,
        COUNT(*) OVER(PARTITION BY hacker_id ORDER BY submission_date) AS days_submitted
            FROM day_hackers),
    full_streak AS(
        SELECT submission_date, COUNT(*) AS cnt
                                    FROM streak
                                        WHERE day_num = days_submitted
                                            GROUP BY submission_date),
    daily_counts AS(
        SELECT submission_date, hacker_id, COUNT(*) AS submissions FROM Submissions GROUP BY submission_date, hacker_id),
    max_hacker AS(
        SELECT submission_date, hacker_id, submissions,
        RANK() OVER(PARTITION BY submission_date ORDER BY submissions DESC, hacker_id ASC) AS rnk
            FROM daily_counts)
        SELECT fs.submission_date,
    fs.cnt, mh.hacker_id, h.name FROM full_streak fs JOIN max_hacker mh ON fs.submission_date = mh.submission_date AND mh.rnk = 1 JOIN Hackers h ON h.hacker_id = mh.hacker_id ORDER BY fs.submission_date;