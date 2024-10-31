def workScheduler(pattern, workHours, dayHours):
    unscheduledDays = 0
    remainingWorkHours = workHours
    for day in pattern:
        if day == "?":
            unscheduledDays += 1
        else:
            remainingWorkHours -= int(day)

    def getFilledPattern(combo):
        p = 0
        filledPattern = ""
        for day in pattern:
            if day == "?":
                filledPattern += str(combo[p])
                p += 1
            else:
                filledPattern += day

        return filledPattern

    def getScheduleCombinations(curCombo, remainingHours):
        if remainingHours == 0 and len(curCombo) == unscheduledDays:
            result.append(getFilledPattern(curCombo))
            return      
        elif remainingHours < 0 or len(curCombo) == unscheduledDays:
            return

        for i in range(0, dayHours+1):
            curCombo.append(i)
            getScheduleCombinations(curCombo, remainingHours - i)
            curCombo.pop()

    result = []
    getScheduleCombinations([], remainingWorkHours)
    return result