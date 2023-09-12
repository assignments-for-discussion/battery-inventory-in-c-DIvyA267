#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
  int i, SoH;
  for(i=0;i<nBatteries;i++)
    {
      SoH=100*presentCapacities[i]/120; // calculating the state of battery for each battery
      if(SoH<=100 && SoH>80) // checking condition for healthy battery
        counts.healthy+=1;
      else if(SoH<=80 && SoH> 63) // checking condition for exchange battery
        counts.exchange+=1;
      else
        counts.failed+=1;
    }   
  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {115, 118, 80, 95, 91, 72};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByHealth();
  return 0;
}
