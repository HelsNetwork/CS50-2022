-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = 'Chamberlin Street';

SELECT day, month, year, name, transcript FROM interviews
WHERE transcript LIKE '%courthouse%' AND day = 28 AND month = 7 AND year = 2020;
-- 3 witnesses: Ruth, Eugene, Raymond.
SELECT hour, minute, activity, license_plate FROM courthouse_security_logs
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10;
-- 2) Check the ATM on Fifer street (date July 28, 2020 - Morning before theft, withdraw money)
-- I found 8 accounts, who withdraw some money
SELECT account_number FROM atm_transactions
WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = 'Fifer Street' AND transaction_type = 'withdraw';

-- 3) 10:15am July 28 Thief called someone. Short call less than a minute.
SELECT caller, receiver, duration FROM phone_calls
WHERE year = 2020 AND month = 7 AND day = 28;
-- I firured out that durations fixed in seconds and I found out and made a clarifying request. 9 phone numbers matching the description were found
SELECT caller, receiver, duration FROM phone_calls
WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60;
-- 4)They planning flite out -  29-07-2020/ Earlist flight. Another person bought plane tickets
-- I found out that there is only 1 airport in the city. This is a regional airport, you can't fly to another country from it
SELECT full_name, city FROM airports
WHERE city = 'Fiftyville';
-- Figured out names and abbreviation all airports exclude Fiftyville
SELECT full_name, abbreviation  FROM airports
WHERE city != 'Fiftyville';

SELECT * FROM flights
JOIN airports
ON flights.origin_airport_id = airports.id
WHERE year = 2020 AND month = 7 AND day = 29
ORDER BY hour, minute;

SELECT passport_number FROM passengers
WHERE flight_id = 43;


SELECT name FROM people
WHERE id IN (
SELECT person_id FROM bank_accounts
WHERE account_number IN (
SELECT account_number FROM atm_transactions
WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = 'Fifer Street' AND transaction_type = 'withdraw'));
--Found 8 names Bobby, Elizabeth, Victoria, Madison, Roy, Danielle, Russell, Ernest

SELECT name FROM people
WHERE license_plate IN (
SELECT license_plate FROM courthouse_security_logs
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 30 AND activity = 'exit');

-- I identify the people who called
SELECT name FROM people
WHERE phone_number IN (
SELECT caller FROM phone_calls
WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60);
---Result: Bobby, Roger, Victoria, Madison, Russell, Evelyn, Ernest, Kimberly

SELECT name FROM people
WHERE passport_number IN (
SELECT passport_number FROM passengers
WHERE flight_id = 36);
-- Bobby Roger Madison Danielle Evelyn Edward Ernest Doris

SELECT name FROM people
WHERE name IN (
SELECT name FROM people
WHERE id IN (
SELECT person_id FROM bank_accounts
WHERE account_number IN (
SELECT account_number FROM atm_transactions
WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = 'Fifer Street' AND transaction_type = 'withdraw'))
INTERSECT
SELECT name FROM people
WHERE license_plate IN (
SELECT license_plate FROM courthouse_security_logs
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 30 AND activity = 'exit')
INTERSECT
SELECT name FROM people
WHERE passport_number IN (
SELECT passport_number FROM passengers
WHERE flight_id = 36)
INTERSECT
SELECT name FROM people
WHERE phone_number IN (
SELECT caller FROM phone_calls
WHERE year = 2020 AND month = 7 AND day = 28 AND duration  < 60)
);

-- Find receiver
SELECT name
FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.receiver
WHERE  year = 2020 AND month = 7 AND day = 28 AND duration  < 60 AND caller = (
SELECT phone_number FROM people
WHERE name = 'Ernest'
);
--Berthold is an accomplice
