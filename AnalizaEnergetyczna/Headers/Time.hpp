#ifndef TIME_HPP
#define TIME_HPP

/**
 * @brief Klasa reprezentująca godzinę i minutę.
 */
class Time {
public:
    /**
     * @brief Konstruktor klasy Time.
     *
     * Tworzy obiekt Time z podaną godziną i minutą.
     *
     * @param hour Godzina (0-23).
     * @param minute Minuta (0-59).
     * @throws std::out_of_range jeśli `hour` lub `minute` są poza zakresem.
     */
    Time(int hour, int minute);

    /**
     * @brief Zwraca godzinę.
     *
     * @return Godzina (0-23).
     */
    [[nodiscard]] int GetHour() const;

    /**
     * @brief Zwraca minutę.
     *
     * @return Minuta (0-59).
     */
    [[nodiscard]] int GetMinute() const;

    /**
     * @brief Operator mniejszości.
     *
     * Porównuje dwa obiekty Time.
     *
     * @param other Referencja do stałego obiektu Time do porównania.
     * @return `true` jeśli czas reprezentowany przez ten obiekt jest wcześniejszy niż czas reprezentowany przez obiekt `other`, `false` w przeciwnym razie.
     */
    bool operator<(const Time& other) const;

    /**
     * @brief Operator większości.
     *
     * Porównuje dwa obiekty Time.
     *
     * @param other Referencja do stałego obiektu Time do porównania.
     * @return `true` jeśli czas reprezentowany przez ten obiekt jest późniejszy niż czas reprezentowany przez obiekt `other`, `false` w przeciwnym razie.
     */
    bool operator>(const Time& other) const;

private:
    /**
     * @brief Godzina (0-23).
     */
    int _hour;
    /**
     * @brief Minuta (0-59).
     */
    int _minute;
};

#endif //TIME_HPP
