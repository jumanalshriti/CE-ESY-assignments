#  Circular Buffer – C Implementation | تنفيذ المخزن الدائري بلغة C

##  Overview | نظرة عامة
المخزن الدائري (Circular Buffer) هو بنية تخزين تعتمد على مبدأ FIFO (First In – First Out)، ويتميز بأنه ذو حجم ثابت، وعند الوصول إلى نهايته يقوم بالالتفاف والعودة للبداية إذا كان هناك مكان متاح للكتابة.

يحتوي المخزن الدائري على:
- مؤشر كتابة (write) يشير إلى الموقع الذي يلي آخر عنصر تم إدخاله.
- مؤشر قراءة (read) يشير إلى أقدم عنصر تم إدخاله (الأول في الدور).
- عداد (count) يمثل عدد العناصر الموجودة داخل المخزن.

هذا المشروع يقدّم تطبيقًا عمليًا لهذه البنية باستخدام لغة C.

---

## How the Code Works | كيفية عمل الكود

### 1- Initialization | التهيئة
يتم أولًا تهيئة:
- حجم المخزن size
- العداد count
- مؤشري القراءة والكتابة read, write بحيث يشيران إلى بداية المخزن.

---

### 2- Helper Functions | التوابع المساعدة

####  not_full_cb  
تابع لاختبار ما إذا كان المخزن ليس ممتلئًا:  
يقوم بمقارنة قيمة count مع حجم المخزن size.

####  not_empty_cb  
تابع لاختبار ما إذا كان المخزن ليس فارغًا:  
يتحقق من أن count لا يساوي الصفر.

---

### 3- Writing Function (write_cb) | تابع الكتابة
- يدخل في حلقة تكرار ويتحقق باستمرار من أن المخزن غير ممتلئ.
- عند توفر مساحة، يتم إدخال الحرف في موقع مؤشر الكتابة.
- يتم زيادة العداد count بمقدار 1.
- يتم تحديث مؤشر الكتابة باستخدام:
  ```c
  write = (write + 1) % size;
  ####English
  #  Circular Buffer – C Implementation

##  Overview
A circular buffer is a storage structure based on the FIFO (First In – First Out) principle.  
It has a fixed size, and when the write index reaches the end of the buffer, it wraps around to the beginning as long as there is available space.

The circular buffer contains:
- A write index that points to the position immediately after the last inserted element.
- A read index that points to the oldest element in the buffer.
- A counter that tracks the number of elements currently stored.

This project provides a C implementation of a circular buffer with dynamic wrapping and special handling for the character -.

---

##  Code Execution Details

### 1- Initialization
The program initializes:
- The buffer size size
- The counter count
- The write and read indices write and read, both starting at the beginning of the buffer

---

### 2- Helper Functions

####  not_full_cb  
Checks whether the buffer is not full by comparing count with the buffer size.

####  not_empty_cb  
Checks whether the buffer is not empty by verifying that count is not zero.

---

### 3- Writing Function (write_cb)
- The function enters a loop and continuously checks whether the buffer is not full.
- If space is available, it writes the input character at the current write index.
- After writing, it increments the counter count by 1.
- The write index is updated using:
  ```c
  write = (write + 1) % size;
