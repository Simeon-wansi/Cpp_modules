# Portfolio Platform - Project Context

## 🎯 Project Overview
A full-stack portfolio management system built with Next.js 15, Supabase, and TypeScript.

## 🏗️ Tech Stack
- **Frontend**: Next.js 15.5.2 (App Router), TypeScript, Tailwind CSS
- **Backend**: Supabase (PostgreSQL), Edge Functions
- **Authentication**: Supabase Auth
- **Deployment Target**: Vercel
- **Location**: UAE (Etisalat ISP - may block Supabase direct access)

## 📂 Project Structure

portfolio-platform/
├── app/
│   ├── (public)/           # Public routes
│   │   ├── page.tsx        # Homepage showing projects
│   │   └── projects/
│   │       └── [slug]/     # Dynamic project pages
│   └── (admin)/            # Admin routes
│       ├── login/          # Authentication
│       └── dashboard/      # Admin panel
│           └── projects/
│               ├── new/    # Create project
│               └── [id]/
│                   └── edit/ # Edit project
├── components/
│   ├── ui/                # Reusable UI components
│   └── features/          # Feature-specific components
├── lib/
│   ├── supabase/         # Database clients
│   ├── types/            # TypeScript types
│   └── utils/            # Helper functions
└── middleware.ts         # Auth middleware (currently disabled)


## 🗄️ Database Schema
- **Table**: `projects`
  - id (UUID, primary key)
  - title (text, required)
  - slug (text, unique)
  - description (text)
  - demo_url (text)
  - github_url (text)
  - featured (boolean)
  - published (boolean)
  - created_at (timestamp)
  - updated_at (timestamp)
- **RLS**: Currently DISABLED for development

## 🔑 Environment Variables


NEXT_PUBLIC_SUPABASE_URL=https://blgvejtippovlcuavljz.supabase.co
NEXT_PUBLIC_SUPABASE_ANON_KEY=[your-anon-key]

## ✅ Completed Features
- Homepage with project grid
- Individual project pages
- Basic admin dashboard
- Create new projects
- View/Edit/Delete projects (CRUD)
- Authentication setup
- Responsive design

## 🚧 Current Issues
1. Login redirect not working properly (stays on login page)
2. Session persistence issues
3. Middleware protection disabled
4. Edit/Delete functionality needs testing

## 🎯 Next Steps
- Fix authentication flow
- Add image upload
- Implement search/filter
- Add analytics
- Deploy to Vercel
- Add loading states
- Improve error handling