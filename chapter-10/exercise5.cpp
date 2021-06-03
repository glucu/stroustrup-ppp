#include "../include/std_lib_facilities.h"

/* Chapter 10: exercise 5
 *
 * Write the function print_year() mentioned in §10. 1 1.2. 
 */

/* COMMENT:
 * I was lazy this morning, I only decided to write the print_year() function
 * and left everything else out, making it be an incomplete program. Sorry,
 * I'll just scold myself later today for it.
 */

void print_year(std::ofstream &ost, Year y) {

    ost << y.year << ":\n";
    for (Month m : y.month)
        if (m.month != not_a_month) {
            ost << '\t' << int_to_month(m.month) << '\n';

            for (int d = 1; d < m.day.size(); ++d)
                for (int h = 0; h < m.day[d].hour.size(); ++h)

                    if (m.day[d].hour[h] != not_a_reading)
                        ost << "\t\t" << d << '\t' << h << '\t'
                            << m.day[d].hour[h] << '\n';
        }
}