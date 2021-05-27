

#include <stdio.h>

#include <stdlib.h>

long long int commonarr[100005], b[100005];

void merge(long long int first, long long int last, long long int mid)
{

    long long int p = first, q = mid + 1, r = first;

    while (p <= mid && q <= last)
    {

        if (commonarr[p] <= commonarr[q])
        {

            b[r] = commonarr[p];

            p = p + 1;

            r = r + 1;
        }

        else
        {

            b[r] = commonarr[q];

            q = q + 1;

            r = r + 1;
        }
    }

    while (p <= mid)
    {

        b[r] = commonarr[p];

        r = r + 1;

        p = p + 1;
    }

    while (q <= last)
    {

        b[r] = commonarr[q];

        r = r + 1;

        q = q + 1;
    }

    for (int i = first; i <= last; i++)
    {

        commonarr[i] = b[i];
    }
}

void sort(long long int first, long long int last)
{

    long long int mid;

    if (first < last)
    {

        mid = (first + last) / 2;

        sort(first, mid);

        sort(mid + 1, last);

        merge(first, last, mid);
    }

    else
    {
        return;
    }
}

long long int BinarySearch(long long int n, long long int find, int num)
{

    printf("%lld ", n);

    long long int low = 0, high = n - 1;

    long long int ans = -1;

    while (low <= high)
    {

        long long int mid = low + (high - low) / 2;

        if (find == commonarr[mid])
        {

            ans = mid;

            if (num == 1)
            {

                high = mid - 1;
            }

            else
            {

                low = mid + 1;
            }
        }

        if (find < commonarr[mid])
        {

            high = mid - 1;
        }

        else
        {

            low = mid + 1;
        }
    }

    return ans;
}

long long int first_occurence(long long int low, long long int high, long long int x, long long int n)
{
    if (high >= low)
    {

        long long int mid = low + (high - low) / 2;

        if ((mid == 0 || x > commonarr[mid - 1]) && commonarr[mid] == x)
        {

            return mid;
        }

        else if (x > commonarr[mid])
        {

            return first_occurence((mid + 1), high, x, n);
        }
        else
        {

            return first_occurence(low, (mid - 1), x, n);
        }
    }
    return -1;
}

long long int last_occurence(long long int low, long long int high, long long int x, long long int n)
{
    if (high >= low)
    {

        long long int mid = low + (high - low) / 2;

        if ((mid == n - 1 || x < commonarr[mid + 1]) && commonarr[mid] == x)
        {

            return mid;
        }
        else if (x < commonarr[mid])
        {

            return last_occurence(low, (mid - 1), x, n);
        }
        else
        {

            return last_occurence((mid + 1), high, x, n);
        }
    }

    return -1;
}

int main()
{

    long long int N, k;

    scanf("%lld%lld", &N, &k);

    long long int array[N + 5], unsorted[N + 5];

    for (int i = 0; i < N; i++)
    {

        scanf("%lld", &array[i]);
    }

    long long int x, count = 0;

    scanf("%lld", &x);

    long long int prefix_sum = 0;

    for (int i = 0; i < k; i++)
    {

        prefix_sum = prefix_sum + array[i];
    }

    commonarr[0] = 2 * k * (prefix_sum);

    for (int i = 1; i < N - k + 1; i++)
    {

        commonarr[i] = commonarr[i - 1] + k * (array[k + i - 1] - array[i - 1]);
    }

    for (int i = 0; i < N - k + 1; i++)
    {

        unsorted[i] = commonarr[i];
    }

    long long int first = 0, last = N - k;

    sort(first, last);

    /*for (int i = 0; i < N - k + 1; i++)
    {

        printf("%lld ", commonarr[i]);
    }*/

    for (int i = 0; i < N - k + 1; i++)
    {

        long long int find = x - unsorted[i] + unsorted[0];

        long long int fir, las;

        long long int low = 0, high = N - k;

        fir = first_occurence(low, high, find, N - k + 1);

        las = last_occurence(low, high, find, N - k + 1);

        /*for ( int i=0 ;i<N-k+1;i++){

            if ( find == commonarr[i]){

                count=count+1;
            }
        }*/

        if (fir != -1)
        {

            count = count + las - fir + 1;
        }
    }

    printf("%lld\n", count);
}
