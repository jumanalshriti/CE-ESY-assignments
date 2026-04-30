#include <stdio.h>

int write = 0; // indicates the writing index
int read = 0;  // indicates the reading index
int count = 0; // indicates number of exist elements

// write function in the buffer
void write_cb(char your_name[], int length)
{
  for (int i = 0; i < length; i++)
  {
    if (not_full_cb(your_name, length)) // testing the buffer is not full to write on it
    {
      scanf(" %c", &your_name[write]);
      count++;

      if (your_name[write] == '-') // testing the value (-) to end the writing on the buffer
      {
        char suffix[6] = {'C', 'E', '-', 'E', 'S', 'Y'};
        write = (write + 1) % length;
        for (int k = 0; k < 6; k++)
        {
          if (not_full_cb(your_name, length))
          {
            your_name[write] = suffix[k]; // add the (CE-ESY) after the name
            count++;
            write = (write + 1) % length;
          }
          else
          {
            break;
          }
        }
        break;
      }

      write = (write + 1) % length; // increase and rotate the write index
    }
  }
}

// reading function from the buffer
void Read_cb(char your_name[], int length)
{

  for (int j = 0; j < length; j++)
  {
    if (not_empty_cb()) // testing if the buffer is not empty to read from it
    {
      printf("%c", your_name[read]);
      read = (read + 1) % length; // increase and rotate the read index
      count--;
    }
    else
    {
      break;
    }
  }
}

// function to test if the buffer is not full
int not_full_cb(char your_name[], int length)
{
  if (count == length)
  {
    printf("the buffer is full\n");
    return 0;
  }
  else
    return 1;
}

// function to test if the buffer is not empty
int not_empty_cb()
{
  if (count == 0)
  {
    return 0;
  }
  else
    return 1;
}

void main()
{
  int size;

  printf("Enter size of your name(buffer):");
  scanf("%d", &size);
  char name[size];
  printf("Enter your name please:");

  write_cb(name, size);
  Read_cb(name, size);
}
