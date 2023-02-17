#include "movie_comedy.h"

int MovieComedy::calculate_late_fees(int num_of_days_past_due) {
    int fee;
    int late_fee_per_day = get_late_fee_per_day_in_dollar();
    if ( num_of_days_past_due <= 0) {
        fee = 0;
    } else if (num_of_days_past_due <= 5) {
        fee = late_fee_per_day;
    } else if (num_of_days_past_due <= 10) {  // Double the fee if past due > 5
        fee = late_fee_per_day * 2;
    } else {
        fee = late_fee_per_day * num_of_days_past_due;
    }
    return fee;
}
