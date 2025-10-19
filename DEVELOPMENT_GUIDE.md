# Portfolio Platform - Development Guide

## 🚀 Quick Start
```bash
# Install dependencies
npm install

# Run development server
npm run dev

# Access at http://localhost:3000

📍 Day 3: Fix Authentication & Complete Admin Features
Task 1: Fix Login System (Priority)
Issue: Login successful but redirect fails

1. Debug current state:

Check browser console for errors
Verify Supabase credentials
Test session persistence


2. Potential fixes:

// Option A: Use Supabase SSR package
   npm install @supabase/ssr
   
   // Option B: Force redirect with replace
   router.replace('/dashboard')
   
   // Option C: Use middleware for auth

   3.Test checklist:

 Can login without errors
 Redirects to dashboard
 Session persists on refresh
 Logout works



Task 2: Complete CRUD Operations

1. Test Edit functionality:

Navigate to /dashboard
Click Edit on any project
Update fields
Save changes
Verify in database


2. Test Delete functionality:

Click Edit → Delete Project
Confirm deletion
Verify removed from list

Task 3: Add Protected Routes
// Enable middleware.ts
// Add session check to all /dashboard routes

📍 Day 4: Enhanced Features
Task 1: Image Upload
// Add to Supabase Storage
// Update project schema with image_url
// Add upload component


Task 2: Search & Filter
// Add search bar to dashboard
// Implement filter by status/featured
// Add pagination

Task 3: Analytics
// Track page views
// Add view_count to projects
// Create analytics dashboard

📍 Day 5: Deployment
Task 1: Prepare for Production

1. Environment setup:

Set production variables
Enable RLS policies
Configure CORS


2. Performance optimization:

Add caching
Optimize images
Implement lazy loading


Task 2: Deploy to Vercel

# Install Vercel CLI
npm i -g vercel

# Deploy
vercel --prod

Task 3: Custom Domain

Configure DNS
Add SSL certificate
Test all features

🐛 Debugging Commands

# Check Supabase connection
node test-connection.js

# Clear Next.js cache
rm -rf .next
npm run dev

# Reset database
# Go to Supabase SQL Editor and run migrations

📝 Git Workflow

# Save progress
git add .
git commit -m "Description of changes"
git push

# Create feature branch
git checkout -b feature/image-upload
# Make changes
git add .
git commit -m "Add image upload"
git checkout main
git merge feature/image-upload


