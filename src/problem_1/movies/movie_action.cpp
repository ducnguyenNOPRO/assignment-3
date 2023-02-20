#include "movie_action.h"

int MovieAction::calculate_late_fees(int num_of_days_past_due) {
    // If mercy rule apply, there is no fee
    if (mercy_rule_apply()) {
        return 0;
    }
    if (num_of_days_past_due <= 0)
        return 0;

    // Base fee = num of day past due * late fee
    // If num of day past due is over 5 days, the fee is double
    // collect expect and actual fees results
    int base_fee = num_of_days_past_due * get_late_fee_per_day_in_dollar();
    return (num_of_days_past_due >= 5) ? 2 * base_fee : base_fee;
}

bool MovieAction::action_movie_mercy_rule_apply() {
    return title.find("pulp fiction") != std::string::npos;
}

bool MovieAction::mercy_rule_apply() {
    return StoreMediaInterface::mercy_rule_apply() && action_movie_mercy_rule_apply();
}