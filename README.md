📘 README.md - نظرة عامة مختصرة

🏦 Bank Management System (C++ OOP Console Application)

نظام إدارة بنك تم تطويره بلغة C++ باستخدام مبادئ البرمجة الكائنية (OOP). يوفر النظام إدارة العملاء والمستخدمين مع صلاحيات مرنة، إجراء المعاملات المالية، وتتبع جلسات الدخول وسجل التحويلات.

---

🧠 المبادئ الرئيسية (OOP Concepts)

· التغليف (Encapsulation): جميع الخصائص private مع دوال get/set باستخدام __declspec(property).
· الوراثة (Inheritance): clsUser و clsBankClient يرثان من clsPerson؛ جميع الشاشات ترث من clsScreen.
· تعدد الأشكال (Polymorphism): دالة _CheckPermissions تستدعي نفس الدالة بأشكال مختلفة حسب الكائن.
· التجريد (Abstraction): clsScreen يختصر التفاصيل المشتركة لعرض الشاشات.
· فصل المسؤوليات (Separation of Concerns): تم تقسيم الكود إلى طبقات: كيانات (Entities)، شاشات (Screens)، دوائل مساعدة (Utilities)، وتخزين بيانات (File Handling).

---

📂 هيكل المشروع (باختصار)

```
BankManagementSystem/
├── Entities/            # كيانات الأعمال
│   ├── clsPerson.h
│   ├── clsUser.h
│   └── clsBankClient.h
├── Screens/             # شاشات الواجهة (كل شاشة في ملف منفصل)
│   ├── clsScreen.h
│   ├── clsMainScreen.h
│   ├── clsLoginScreen.h
│   ├── clsManageUsersScreen.h
│   ├── clsUserListScreen.h, clsAddNewUserScreen.h, clsUpdateUserScreen.h, clsDeleteUserScreen.h, clsFindUserScreen.h
│   ├── clsClientListScreen.h, clsAddNewClientScreen.h, clsUpdateClientScreen.h, clsDeleteClientScreen.h, clsFindClientScreen.h
│   └── clsTransactionsScreen.h, clsLoginRegisterScreen.h
├── Utilities/           # دوال مساعدة
│   ├── clsInputValidate.h
│   ├── clsString.h
│   ├── clsUtil.h (تشفير)
│   └── clsDate.h
├── Global/              # متغير الجلسة
│   └── Global.h (CurrentUser)
└── Data/                # ملفات البيانات (تنشأ تلقائياً)
    ├── Users.txt
    ├── Clients.txt
    ├── LoginRegister.txt
    └── TransferLog.txt
```

---

✨ الميزات الأساسية

· تسجيل الدخول مع ثلاث محاولات، وتشفير كلمة المرور، وتسجيل وقت الدخول.
· صلاحيات مرنة باستخدام enum و bitwise (إدارة كاملة للمستخدمين).
· إدارة المستخدمين: عرض، إضافة، حذف، تحديث، بحث – كل عملية تتحقق من الصلاحية.
· إدارة العملاء: نفس عمليات المستخدمين مع عمليات مالية (إيداع، سحب، تحويل).
· سجل التحويلات: تسجيل كل عملية تحويل (التاريخ، الحسابات، المبلغ، العمولة، الرصيد بعد التنفيذ).
· واجهة تفاعلية: قوائم واضحة، تأكيد العمليات، عرض بيانات منسقة.

---

🛠️ الإضافات التي قمت بتطويرها بنفسي خارج الكورس 
· تطوير شاشة تحديث العميل clsUpdateClientScreen:
  · فصل القائمة الفرعية في دوال مستقلة (_ShowUpdateMenu, _PerformUpdateOption, _ReadUpdateOption).
  · استخدام حلقة while لتصفح الخيارات دون استدعاء ذاتي متكرر.
  · حفظ فوري بعد كل تعديل جزئي مع رسالة نجاح/فشل.
· تطوير شاشة تحديث المستخدم clsUpdateUserScreen:
  · إمكانية تحديث حقل واحد أو جميع الحقول.
  · عرض بيانات المستخدم الحالية قبل التحديث.
  · تكامل كامل مع نظام الصلاحيات.
· إضافة تأكيدات قبل العمليات الحساسة باستخدام دالة IsSoureYesOrNo.
· تحسين دالة التحقق من الصلاحية لتتطابق مع التعدادات الأصلية.

---

🔐 الأمان والتتبع

· تشفير كلمات المرور قبل تخزينها في الملفات.
· سجل تسجيل الدخول (LoginRegister.txt) مع الوقت والتاريخ.
· سجل التحويلات (TransferLog.txt) مع تفاصيل كاملة.
· منع حذف المستخدم Admin.
· التحقق من الصلاحيات قبل دخول أي شاشة.

---

▶️ كيفية التشغيل

1. فتح المشروع في بيئة تطوير C++ (Visual Studio، Code::Blocks، إلخ).
2. بناء المشروع (Build).
3. تشغيل الملف التنفيذي.
4. تسجيل الدخول باستخدام بيانات مستخدم موجود في Users.txt


---

📚 الخلاصة

هذا المشروع يوضح كيفية بناء تطبيق متكامل باستخدام OOP في C++، مع تطبيق مفاهيم التغليف، الوراثة، الفصل بين المسؤوليات، وإعادة استخدام الكود. تم تنفيذه بطريقة تسهل الصيانة وإضافة ميزات جديدة.

---

👨‍💻 Developer: [عبد السلام إسماعيلالقاضي]
📅 Date: مارس 2026
