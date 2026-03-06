SELECT CASE WHEN extract(dow from current_date) = 0 THEN 'domingo'
    WHEN extract(dow from current_date) = 1 THEN 'segunda-feira'
    WHEN extract(dow from current_date) = 2 THEN 'terça-feira'
    WHEN extract(dow from current_date) = 3 THEN 'quarta-feira'
    WHEN extract(dow from current_date) = 4 THEN 'quinta-feira'
    WHEN extract(dow from current_date) = 5 THEN 'sexta-feira'
    WHEN extract(dow from current_date)=6 THEN 'sábado'
END AS "Nome do dia da semana";

SELECT NOME,
    DTNASCIMENTO,
    AGE(DTNASCIMENTO) AS "Idade [ano/mês/dia]",
    EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) AS "Idade do Aluno"
FROM ALUNO;

SELECT NOME,
    EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) AS "Idade do Aluno",
    CASE WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) <=20 THEN '1. até 20 anos'
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) BETWEEN 21 AND 30 THEN '2. 21 a 30 anos'
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) BETWEEN 31 AND 40 THEN '3. 31 a 40 anos'
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) BETWEEN 41 AND 50 THEN '4. 41 a 50 anos'
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) BETWEEN 51 AND 60 THEN '5. 51 a 60 anos'
        WHEN EXTRACT(YEAR FROM AGE(DTNASCIMENTO)) > 60 THEN '6. mais de 60 anos'
    END AS "Faixa Etária"
FROM ALUNO;