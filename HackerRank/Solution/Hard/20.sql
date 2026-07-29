/*
Enter your query here.
*/
SELECT con.contest_id, con.hacker_id, con.name,
    SUM(sub.total_submissions) AS total_submissions,
    SUM(sub.total_accepted_submissions) AS total_accepted_submissions,
    SUM(vie.total_views) AS total_views,
    SUM(vie.total_unique_views) AS total_unique_views
FROM Contests con

JOIN Colleges col ON con.contest_id = col.contest_id

JOIN Challenges chal ON col.college_id = chal.college_id

LEFT JOIN (
    SELECT challenge_id, 
           SUM(total_views) AS total_views, 
           SUM(total_unique_views) AS total_unique_views
    FROM View_Stats
    GROUP BY challenge_id
) vie ON chal.challenge_id = vie.challenge_id

LEFT JOIN (
    SELECT challenge_id, 
           SUM(total_submissions) AS total_submissions, 
           SUM(total_accepted_submissions) AS total_accepted_submissions
    FROM Submission_Stats
    GROUP BY challenge_id
) sub ON chal.challenge_id = sub.challenge_id

GROUP BY con.contest_id, con.hacker_id, con.name
HAVING SUM(sub.total_submissions) != 0
    OR SUM(sub.total_accepted_submissions) != 0
    OR SUM(vie.total_views) != 0
    OR SUM(vie.total_unique_views) != 0
ORDER BY con.contest_id;