-- 코드를 입력하세요
SELECT PT_NAME, PT_NO, GEND_CD, AGE, ifnull(TLNO, 'NONE') TLNO
FROM PATIENT
WHERE GEND_CD = 'W'
and AGE <= 12
ORDER BY AGE desc, PT_NAME